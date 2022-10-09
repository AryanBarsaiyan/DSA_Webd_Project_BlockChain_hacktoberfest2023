                   ............................INTRODUCTION TO DAPPS.............
                   
                   A decentralized application (dapp) is an application built on a decentralized network that combines a smart contract and a frontend user interface. On Ethereum, smart contracts are accessible and transparent – like open APIs – so your dapp can even include a smart contract that someone else has written.

PREREQUISITES
Before learning about dapps, you should cover the blockchain basics and read about the Ethereum network and how it's decentralized.

DEFINITION OF A DAPP
A dapp has its backend code running on a decentralized peer-to-peer network. Contrast this with an app where the backend code is running on centralized servers.

A dapp can have frontend code and user interfaces written in any language (just like an app) to make calls to its backend. Furthermore, its frontend can get hosted on decentralized storage such as IPFS.

Decentralized - dapps operate on Ethereum, an open public decentralized platform where no one person or group has control
Deterministic - dapps perform the same function irrespective of the environment in which they get executed
Turing complete - dapps can perform any action given the required resources
Isolated - dapps are executed in a virtual environment known as Ethereum Virtual Machine so that if the smart contract has a bug, it won’t hamper the normal functioning of the blockchain network
On smart contracts
To introduce dapps, we need to introduce smart contracts – a dapp's backend for lack of a better term. For a detailed overview, head to our section on smart contracts.

A smart contract is code that lives on the Ethereum blockchain and runs exactly as programmed. Once smart contracts are deployed on the network you can't change them. Dapps can be decentralized because they are controlled by the logic written into the contract, not an individual or company. This also means you need to design your contracts very carefully and test them thoroughly.

BENEFITS OF DAPP DEVELOPMENT
Zero downtime – Once the smart contract is deployed on the blockchain, the network as a whole will always be able to serve clients looking to interact with the contract. Malicious actors, therefore, cannot launch denial-of-service attacks targeted towards individual dapps.
Privacy – You don’t need to provide real-world identity to deploy or interact with a dapp.
Resistance to censorship – No single entity on the network can block users from submitting transactions, deploying dapps, or reading data from the blockchain.
Complete data integrity – Data stored on the blockchain is immutable and indisputable, thanks to cryptographic primitives. Malicious actors cannot forge transactions or other data that has already been made public.
Trustless computation/verifiable behavior – Smart contracts can be analyzed and are guaranteed to execute in predictable ways, without the need to trust a central authority. This is not true in traditional models; for example, when we use online banking systems, we must trust that financial institutions will not misuse our financial data, tamper with records, or get hacked.
DRAWBACKS OF DAPP DEVELOPMENT
Maintenance – Dapps can be harder to maintain because the code and data published to the blockchain are harder to modify. It’s hard for developers to make updates to their dapps (or the underlying data stored by a dapp) once they are deployed, even if bugs or security risks are identified in an old version.
Performance overhead – There is a huge performance overhead, and scaling is really hard. To achieve the level of security, integrity, transparency, and reliability that Ethereum aspires to, every node runs and stores every transaction. On top of this, proof-of-stake consensus takes time as well.
Network congestion – When one dapp uses too many computational resources, the entire network gets backed up. Currently, the network can only process about 10-15 transactions per second; if transactions are being sent in faster than this, the pool of unconfirmed transactions can quickly balloon.
User experience – It may be harder to engineer user-friendly experiences because the average end-user might find it too difficult to set up a tool stack necessary to interact with the blockchain in a truly secure fashion.
Centralization – User-friendly and developer-friendly solutions built on top of the base layer of Ethereum might end up looking like centralized services anyways. For example, such services may store keys or other sensitive information server-side, serve a frontend using a centralized server, or run important business logic on a centralized server before writing to the blockchain. Centralization eliminates many (if not all) of the advantages of blockchain over the traditional model.
The Blockchain Makes dApps Possible
Since Bitcoin launched more than a decade ago, blockchain protocols are constantly being developed and refined to unlock new functionalities and use cases. Now there is a budding industry of decentralized applications (dApps) built on blockchain — everything from finance to gaming to web browsing to collecting art.

Though most dApps are built with Ethereum, all dApps are built using blockchain technology. These dApps rely on blockchains to process data through distributed networks and execute transactions with smart contracts. Smart contracts are automated, self-executing agreements that make transactions between two parties seamless, quick, and automatic. They are the key element of dApp technology, and can be combined to create powerful software which can be applied across different industries.

Just like developers build applications for mobile and desktop devices, dApp developers create applications to function on specific blockchain networks. The vast majority of dApp development is on the Ethereum blockchain. As a result, the Ethereum blockchain supports the vast majority of activity across the dApp ecosystem.

Web Apps vs. Decentralized Apps
Trello, Slack, and Twitter are examples of companies that offer web applications. The usability of traditional web applications depends on two elements: the front end and the back end. Web applications use software that lives on centralized web servers, not the local operating system of any given device. Devices and servers communicate via coding messages through the Hypertext Transfer Protocol (HTTP). For instance, when you open Twitter on your web browser, the feed on display (the front end) is drawn from data held on the company's web server (the back end).

While the internet channels huge amounts of data through massive, centralized servers, a blockchain represents hundreds or even thousands of machines that share the transactional burden over a distributed network. On the front end, decentralized apps and websites use the same technology to render a page on the internet. However, on the back end, dApps communicate with their respective blockchain networks through a wallet, which serves as a bridge to the blockchain ecosystem.

Wallets manage your blockchain address and the cryptographic keys necessary to identify and authenticate yourself. Instead of using the HTTP protocol to communicate with the blockchain, dApp wallets trigger smart contracts that interact with the blockchain and execute transactions. A dApp, then, is the front-end user interface (UI) that communicates with smart contracts that transact on the blockchain, at which point the distributed network of nodes that makes up the blockchain validates and confirms the dApp data. While a well-designed decentralized application user experience (UX) may not seem so different from a web app, it differs from the latter in that it lacks servers, HTTP, and potential censorship.

Decentralized App Criteria
Although it's apparent that dApp architecture differs from conventional platforms, what constitutes a dApp is still being defined. However, a dApp generally meets these four main criteria:

A dApp is entirely open source, with no entity owning the majority of the coins or tokens. By way of its open-source nature, changes to the protocol must be decided via consensus of its network users.

A dApp's data must be stored on a decentralized blockchain.

A dApp needs to generate digital assets that act as a proof of value.

A dApp's assets are distributed as rewards on the network.

Based on this definition, the Bitcoin blockchain classifies as a dApp because it adheres to all four criteria. Let’s run through the dApp criteria for Bitcoin:

Bitcoin operates on open source code, no single entity owns the majority of bitcoin (BTC) in circulation, and the Proof-of-Work (PoW) consensus mechanism guides governance.

Bitcoin and all its data live on the blockchain.

Bitcoin generates coins that act as proof of value resulting from the mining process.

Bitcoin distributes bitcoin cryptocurrency to miners as a mining reward.

Under this definition, many cryptocurrencies can be considered rudimentary versions of dApps, even without smart contract functionality and web interfaces. A blockchain itself can be classified as a dApp. Blockchains can host dApps that have their own blockchains, like Bitcoin. Or, dApps that are not blockchain-based can be built on top of an existing blockchain, which is the case with many of the dApps that run on Ethereum.

The Future of Decentralized Apps
Although Bitcoin can arguably be called the first dApp, Ethereum has since become the primary growth driver of the dApp ecosystem. This is largely because of its smart contracts, network effect, and user base. As the decentralized finance (DeFi) market expands its use cases and adoption, dApps present an essential on-ramp to new audiences by deploying user interfaces that emulate conventional web applications while accessing the new capabilities of blockchain. In doing so, dApps are in many ways expanding the functionality of the internet through blockchain.

Regardless of the underlying blockchain in use, interest in dApps is growing fast — and the movement has only just begun. As blockchain continues to develop at a rapid pace, it’s probable that finance, gaming, online markets, and social media will all become blockchain-based dApps.
