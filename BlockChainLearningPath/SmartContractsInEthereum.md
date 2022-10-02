                           ...............Getting started with Smart Contracts on Ethereum.....................
                           
0. Basic Concepts
1. 
This guide assumes you have a basic level of technical understanding on how cryptocurrencies and blockchains work. If you don’t, I recommend skimming over Andreas Antonopoulos’ Mastering Bitcoin book, Consensys’ “Just Enough Bitcoin for Ethereum” guide, or at least watching this short video by Scott Driscoll. To continue ahead you should know what a public and private key are, why a blockchain needs miners, how decentralized consensus is reached, what a transaction is, and the concepts of transaction scripting and smart contracts.

Two other important and related concepts you’ll need to understand before working with Ethereum are the Ethereum Virtual Machine and gas.

Ethereum was designed as a smart contract platform. Its origin is actually linked to a critique made by Vitalik Buterin on bitcoin as a very limited smart contract platform. The Ethereum Virtual Machine (EVM) is where smart contracts run in Ethereum. It provides a more expressive and complete language than bitcoin for scripting. In fact, it is a Turing Complete programming language. A good metaphor is that the EVM is a distributed global computer where all smart contracts are executed.

Given that smart contracts run in the EVM, there must be a mechanism to limit the resources used by each contract. Every single operation that is executed inside the EVM is actually simultaneously executed by every node in the network. This is why gas exists. An Ethereum transaction contract code can trigger data reads and writes, do expensive computations like using cryptographic primitives, make calls (send messages) to other contracts, etc. Each of these operations have a cost measured in gas, and each gas unit consumed by a transaction must be paid for in Ether, based on a gas/Ether price which changes dynamically. This price is deducted from the Ethereum account sending the transaction. Transactions also have a gas limit parameter that is an upper bound on how much gas the transaction can consume, and is used as a safe-guard against programming errors that could deplete an account’s funds. You can read more about gas here.

1. Setting up your environment
So, you know the basics, let’s set everything up to code! To start developing Ethereum apps (or DApps, for decentralized applications, as many people like to call them), you’ll need a client to connect to the network. It will act as your window to the distributed network, and provide a view of the blockchain, where all the EVM state is represented.

There are various compatible clients for the protocol, the most popular being geth, a Go language implementation. However, it’s not the most developer-friendly. The best option I’ve found is the testrpc node (yes, the name sucks). Trust me, it will save you a lot of time. Install it and run it (you may need to prepend sudo depending on your setup):

$ npm install -g ethereumjs-testrpc
$ testrpc
You should run testrpc in a new terminal and leave it running while you develop. Each time you run testrpc, it will generate 10 new addresses with simulated test funds for you to use. This is not real money and you’re safe to try anything with no risk of losing funds.

The most popular language for writing smart contracts in Ethereum is Solidity, so we’ll be using that. We’re also using the Truffle development framework, which helps with smart contract creation, compiling, deployment and testing. Let’s start (again, you may need to prepend sudo depending on your setup):

# First, let's install truffle
$ npm install -g truffle

# let's setup our project
$ mkdir solidity-experiments
$ cd solidity-experiments/
$ truffle init
Truffle will create all the files for an example project, including contracts for MetaCoin, a sample token contract.

You should be able to compile the example contracts by running truffle compile. Then, to deploy the contracts to the simulated network using the testrpc node we have running, you need to run truffle migrate:

$ truffle compile
Compiling ConvertLib.sol...
Compiling MetaCoin.sol...
Compiling Migrations.sol...
Writing artifacts to ./build/contracts

$ truffle migrate
Using network 'development'.

Running migration: 1_initial_migration.js
Deploying Migrations...
... 0x686ed32f73afdf4a84298642c60e2002a6d0d736a5478cc8cb22a655ac018a67
Migrations: 0xa7edbac1156f98907a24d18df8104b5b1bd7027c
Saving successful migration to network...
... 0xe3bf1e50d2262d9ffb015091e5f2974c8ebe0d6fd0df97a7dbcde8a0e51c694a
Saving artifacts...
Running migration: 2_deploy_contracts.js
Deploying ConvertLib...
... 0x2e0e6718f01d0da6da2ada13d6e4ad662c5a20e784e04c404e9d4ef1d392bdae
ConvertLib: 0xf4388ce4d4ce8a443228d65ecfa5149205db049f
Linking ConvertLib to MetaCoin
Deploying MetaCoin...
... 0xb03a3cde0672a2bd4dda6c01dd31641d95bd680c4e21162b3370ed6db7a5620d
MetaCoin: 0x4fc68713f7ac86bb84ac1ef1a09881a9b8d4100f
Saving successful migration to network...
... 0xb9a2245c27ff1c6506c0bc6349caf86a31bc9f700388defe04566b6d237b54b6
Saving artifacts...
Note to Mac OS X users: Truffle is sometimes confused by .DS_Store files. If you get an error mentioning one of those files, just delete it.

We just deployed the sample contracts to our testrpc node. Wohoo! That was easy, right? Time to create our own contract now!

2. Writing your first Ethereum smart contract
In this guide we’ll be writing a simple Proof of Existence smart contract. The idea is to create a digital notary that stores hashes of documents as proofs of their existence. Use truffle create contract to get started:

$ truffle create contract ProofOfExistence1
Now open contracts/ProofOfExistence1.sol in your favorite text editor (I use vim with Solidity syntax highlighting), and paste this initial version of the code:

pragma solidity ^0.4.15;
// Proof of Existence contract, version 1
contract ProofOfExistence1 {
  // state
  bytes32 public proof;
  // calculate and store the proof for a document
  // *transactional function*
  function notarize(string document) {
    proof = proofFor(document);
  }
  // helper function to get a document's sha256
  // *read-only function*
  function proofFor(string document) constant returns (bytes32) {
    return sha256(document);
  }
}
We’ll start with something simple but incorrect and move towards a better solution. This is a definition of a Solidity contract, which is like a class in other programming languages. Contracts have state and functions. It is important to distinguish two kinds of functions that can appear in a contract:

Read-only (constant) functions: functions that don’t perform any state changes. They only read state, perform computations, and return values. As these functions can be resolved locally by each node, they cost no gas. Marked with the keyword constant.
Transactional functions: functions that perform a state change in the contract or move funds. As these changes need to be reflected in the blockchain, transactional function execution requires sending a transaction to the network and spending gas.

Our contract above has one of each kind, marked in the documentation. We’ll see how the kind of function we’re using with modifies how we interact with the smart contract in the next section.

This simple version only stores one proof at a time, using the data type bytes32, or 32 bytes, which is the size of a sha256 hash. The transactional function notarize allows one to store the hash of a document in our smart contract’s state variable proof. Said variable is public, and is the only way a user of our contract has to verify if a document has been notarized. We’ll do that ourselves shortly, but first…

Let’s deploy ProofOfExistence1 to the network! This time, you’ll have to edit the migration file (migrations/2_deploy_contracts.js) to make Truffle deploy our new contract. Replace the contents with the following:

var ProofOfExistence1 = artifacts.require("./ProofOfExistence1.sol");
module.exports = function(deployer) {
  deployer.deploy(ProofOfExistence1);
};
To run this migration again, you’ll need to use the reset flag, to make sure it runs again.

truffle migrate --reset
More on how Truffle migrations work can be found here.

3. Interacting with your smart contract
Now that our contract is deployed, let’s play with it! We can send messages to it via function calls and read its public state. We’ll use the Truffle console for that:

$ truffle console
// get the deployed version of our contract
truffle(default)> var poe = ProofOfExistence1.at(ProofOfExistence1.address)
// and print its address 
truffle(default)> poe.address
0x3d3bce79cccc331e9e095e8985def13651a86004
// let's register our first "document"
truffle(default)> poe.notarize('An amazing idea')
{ tx: '0x18ac...cb1a',
  receipt: 
   { transactionHash: '0x18ac...cb1a',
     ...
   },
  logs: [] }
// let's now get the proof for that document
truffle(default)> poe.proofFor('An amazing idea')
0xa3287ff8d1abde95498962c4e1dd2f50a9f75bd8810bd591a64a387b93580ee7
// To check if the contract's state was correctly changed:
truffle(default)> poe.proof()
0xa3287ff8d1abde95498962c4e1dd2f50a9f75bd8810bd591a64a387b93580ee7
// The hash matches the one we previously calculated
First thing we do is obtain a representation of our deployed contract and store it in a variable called poe.

We then call the transactional function notarize, which involves a state change. When we call a transactional function, we get a Promise that resolves to a transaction object, not what the actual function returns. Remember that to change the EVM state we need to spend gas and send a transaction to the network. That’s why we get a transaction information object as the result of the Promise, referring to the transaction that did this state change. In this case, we are not interested in the transaction id, so we just discard the Promise. When writing a real app, we’ll want to save it to check the resulting transaction and catch errors.

Next, we call the read-only (constant) function proofFor. Remember to mark your read-only functions with the keyword constant, or else Truffle will try to craft a transaction to execute them. This is a way to tell Truffle that we’re not interacting with the blockchain but just reading from it. By using this read-only function, we obtain the sha256 hash of the ‘An amazing idea’ “document”.

We now need to contrast this with the state of our smart contract. To check if the state changed correctly, we need to read the proof public state variable. To get the value of a public state variable, we can call a function of the same name, which returns a Promise of its value. In our case, the output hash is the same, so everything worked as expected 🙂

For more info on how to interact with contracts, read this section of the Truffle documentation.

As you can see from the snippet above, our first version of the Proof of Existence smart contract seems to be working! Good work! It’s only good for registering one document at a time, though. Let’s create a better version.

4. Iterating the contract code
Let’s change the contract to support multiple document proofs. Copy the original file with the name contracts/ProofOfExistence2.sol and apply these changes. The main changes are: we change the proof variable into a bytes32 array and call it proofs, we make it private, and we add a function to check if a document has already been notarized by iterating that array.

pragma solidity ^0.4.15;
// Proof of Existence contract, version 2
contract ProofOfExistence2 {
  // state
  bytes32[] private proofs;
  // store a proof of existence in the contract state
  // *transactional function*
  function storeProof(bytes32 proof) {
    proofs.push(proof);
  }
// calculate and store the proof for a document
  // *transactional function*
  function notarize(string document) {
    bytes32 proof = proofFor(document);
    storeProof(proof);
  }
// helper function to get a document's sha256
  // *read-only function*
  function proofFor(string document) constant returns (bytes32) {
    return sha256(document);
  }
// check if a document has been notarized
  // *read-only function*
  function checkDocument(string document) constant returns (bool) {
    bytes32 proof = proofFor(document);
    return hasProof(proof);
  }
  // returns true if proof is stored
  // *read-only function*
  function hasProof(bytes32 proof) constant returns (bool) {
    for (uint256 i = 0; i < proofs.length; i++) {
      if (proofs[i] == proof) {
        return true;
      }
    }
    return false;
  }
}
Let’s interact with the new functions: (remember to update migrations/2_deploy_contracts.js to include the new contract and run truffle migrate --reset)

// deploy contracts
truffle(default)>  migrate --reset
// Get the new version of the contract
truffle(default)> var poe = ProofOfExistence2.at(ProofOfExistence2.address)
// let's check for some new document, and it shouldn't be there.
truffle(default)> poe.checkDocument('hello')
false
// let's now add that document to the proof store
truffle(default)> poe.notarize('hello')
{ tx: '0x1d2d...413f',
  receipt: { ... },
  logs: []
}
// let's now check again if the document has been notarized!
truffle(default)> poe.checkDocument('hello')
true
// success!
// we can also store other documents and they are recorded too
truffle(default)> poe.notarize('some other document');
truffle(default)> poe.checkDocument('some other document')
true
This version is better than the first, but still has some problems. Note that every time we want to check if a document was notarized, we need to iterate through all existing proofs. This makes the contract spend more and more gas on each check as more documents are added. A better structure to store proofs is a map. Luckily, Solidity supports maps, and calls them mappings. Another thing we’ll improve in this version is removing all that extra comments marking read-only or transactional functions. I think you get it by now 🙂

Here’s the final version, which should be pretty easy to understand because you followed along previous versions:

pragma solidity ^0.4.15;
// Proof of Existence contract, version 3
contract ProofOfExistence3 {
  mapping (bytes32 => bool) private proofs;
  // store a proof of existence in the contract state
  function storeProof(bytes32 proof) {
    proofs[proof] = true;
  }
  // calculate and store the proof for a document
  function notarize(string document) {
    var proof = proofFor(document);
    storeProof(proof);
  }
  // helper function to get a document's sha256
  function proofFor(string document) constant returns (bytes32) {
    return sha256(document);
  }
  // check if a document has been notarized
  function checkDocument(string document) constant returns (bool) {
    var proof = proofFor(document);
    return hasProof(proof);
  }
  // returns true if proof is stored
  function hasProof(bytes32 proof) constant returns(bool) {
    return proofs[proof];
  }
}
That looks good enough. And it works exactly as the 2nd version. To try it out, remember to update the migration file and run truffle migrate --reset again. All the code in this tutorial can be found in this GitHub repo.

5. Deploying to the real testnet network
Once you’ve tested your contract extensively using testrpc in the simulated network, you’re ready to try it in the real network! To do that, we need a real testnet/livenet Ethereum client. Follow these instructions to install geth.

During development, you should run nodes in testnet mode, so that you can test everything out without risking real money. Testnet mode (also known as Morden in Ethereum) is basically identical to the real Ethereum, but the Ether token there has no monetary value. Don’t be lazy and remember to always develop in testnet mode, you will regret it if you lose real Ether due to a programming error (trust me on that, hehe).

Run geth in testnet mode, with RPC server enabled:

geth --testnet --rpc console 2>> geth.log
This will open a console where you can type in basic commands to control your node/client. Your node will begin downloading the testnet blockchain, and you can check progress by checking eth.blockNumber. While the blockchain is downloading, you can still run commands. For example, let’s create an account: (remember the password!)

> personal.newAccount()
Passphrase:
Repeat passphrase:

"0xa88614166227d83c93f4c50be37150b9500d51fc"
Let’s send some coins there and check the balance. You can get free testnet Ether here. Just copy-paste the address you just generated and this faucet will send you some testnet Ether. To check you balance, run:

> eth.getBalance(eth.accounts[0])
0
It will show no balance because your node hasn’t synced with the rest of the network yet. While you wait for that, check your balance in a testnet block explorer. There, you can also see the current testnet highest block number (#1819865 at the time of writing), which you can use in combination with eth.blockNumber to know when your node has synced completely.

Once your node has synced, you’re ready to deploy the contracts to the testnet using Truffle. First, unlock your main geth account, so that Truffle can use it. And be sure that it holds some balance, or you won’t be able to push a new contract to the network. On geth run:

> personal.unlockAccount(eth.accounts[0], "mypassword", 24*3600)
true
> eth.getBalance(eth.accounts[0])
1000000000000000000
Ready to go! If some of these two are not working for you, check the steps above and make sure you’ve completed them correctly. Now run:

$ truffle migrate --reset
Note that this time, it will take longer to complete, as we’re connecting to the actual network and not one simulated by testrpc. Once it completes, you can interact with the contract using the same approach as before.

The testnet-deployed version of ProofOfExistence3 can be found at the address 0xcaf216d1975f75ab3fed520e1e3325dac3e79e05. (Feel free to interact with it and send your proofs!)

I’ll leave the details on how to deploy to the live network to the reader. You should only do this once you’ve extensively tested your contracts in simulated and test networks. Remember any programming error can result in monetary loss in the livenet!

Smart Contract security in Ethereum is hard
“Smart contracts are pretty difficult to get right.” Emin Gün Sirer.

Given that by nature, smart contracts are computer code that define how money moves, I couldn’t end this guide without even a small note on security. I’ll be talking about smart contract security in much more depth at future posts (edit: like this one), but here are some quick notes to get you started.

Some problems you should be aware of (and avoid):

Reentrancy: Do not perform external calls in contracts. If you do, ensure that they are the very last thing you do.
Send can fail: When sending money, your code should always be prepared for the send function to fail.
Loops can trigger gas limit: Be careful when looping over state variables, which can grow in size and make gas consumption hit the limits.
Call stack depth limit: Don’t use recursion, and be aware that any call can fail if stack depth limit is reached. EDIT: this is no longer a problem.
Timestamp dependency: Do not use timestamps in critical parts of the code, because miners can manipulate them.
These are provided just as examples of unexpected behaviors that can lead for theft or destruction of funds in your smart contract. The moral is: if you’re writing smart contracts, you’re writing code that handles real money. You should be very careful! Write tests, do code reviews, and audit your code.

The best way to avoid obvious security problems is to have a solid understanding of the language. I recommend you read the Solidity documentation if you have the time. We still need better tools for acceptable smart contract security. (Edit: close to the original publishing of this post, we launched the OpenZeppelin library, and we’ve recently announced zeppelinOS.

That’s it! I hope you enjoyed reading this guide and learning your first steps in programming smart contracts in Ethereum! This is still a very new industry and there’s lot of room for new apps and tools. Feel free to contact me with ideas or prototypes.
