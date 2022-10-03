var randomNumber1 = Math.floor(Math.random()*6)+1;
var randomNumber2 = Math.floor(Math.random()*6)+1;
var randomdiceimage1 = "images/dice" + randomNumber1 + ".png";
var randomdiceimage2 = "images/dice" + randomNumber2 + ".png";

document.querySelector(".img1").setAttribute("src", randomdiceimage1);

document.querySelector(".img2").setAttribute("src", randomdiceimage2);

if(randomNumber1>randomNumber2)
{
  document.querySelector("h1").innerHTML = "🚩Player 1 wins";
}
if(randomNumber1<randomNumber2)
{
  document.querySelector("h1").innerHTML = "Player 2 wins🚩";
}
if(randomNumber1===randomNumber2)
{
  document.querySelector("h1").innerHTML = "! Tie";
}
