let seconds=0;
let minutes=0;
let hours=0;

function startTimer(){
  seconds++;

  if(seconds/60===1){
    seconds=0;
    minutes++;

    if(minutes/60===1){
      minutes=0;
      hours++;
    }
  }

  document.getElementById('clock').innerHTML=hours+':'+minutes+':'+seconds;

}

let timer=window.setInterval(startTimer,1000);


let x=0
function points(){
  x=x+1;
}