'use strict';

let secretNumber = Math.trunc(Math.random() * 20) + 1;
let score = 20;
let highscore = 0;
let won = false;

const displayMessage = function (message) {
    document.querySelector('.message').textContent = message;
};

document.querySelector('.check').addEventListener('click', function(e) {
    let guess = Number(document.querySelector('.guess').value);
    console.log(guess, typeof guess);

    if (!won && score > 0) {
        if (!guess) {  // When there is no input
            displayMessage('⛔️ No number!');
        } else if (guess === secretNumber) {  // When the guess is correct
            displayMessage('🎉 Correct Number!');
            document.querySelector('.number').textContent = secretNumber;

            document.querySelector('body').style.backgroundColor = '#60b347';
            document.querySelector('.number').style.width = '30rem';
            won = true;
            if (score > highscore) {
                document.querySelector('.highscore').textContent = score;
            }
            document.querySelector('.guess').value = '';
        } else if (guess !== secretNumber) {  // When the guess is too high
            displayMessage(guess > secretNumber ? '🔥 Too high!' : '🔥 Too low!');

            score--;
            document.querySelector('.score').textContent = score;

        }
    } 
    if (!won && score === 0) {
        displayMessage('💀 Game over!');
        document.querySelector('.number').textContent = secretNumber;
        document.querySelector('body').style.backgroundColor = '#e74c3c';
        document.querySelector('.number').style.width = '30rem';
    }

});

document.querySelector('.again').addEventListener('click', function () {
    score = 20;
    secretNumber = Math.trunc(Math.random() * 20) + 1;
  
    displayMessage('Start guessing...');
    document.querySelector('.score').textContent = score;
    document.querySelector('.number').textContent = '?';
    document.querySelector('.guess').value = '';
  
    document.querySelector('body').style.backgroundColor = '#222';
    document.querySelector('.number').style.width = '15rem';
    won = false;
});
