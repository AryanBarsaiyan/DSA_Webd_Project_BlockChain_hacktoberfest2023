let storageEasy = localStorage.getItem('highScoreEasy');

function highScEasy(){
  if(storageEasy!==null){
    if(x<parseInt(storageEasy)){
      localStorage.setItem('highScoreEasy',x);
    }
  }
  else{
    localStorage.setItem('highScoreEasy',x);
  }
  hs=localStorage.getItem('highScoreEasy');
}

function answer(){
  const question = document.querySelectorAll('.item');
  const answer = document.querySelectorAll('.box');

  if(question && answer && answer[6].style.backgroundColor===question[0].style.backgroundColor && answer[7].style.backgroundColor===question[1].style.backgroundColor && answer[8].style.backgroundColor===question[2].style.backgroundColor && answer[11].style.backgroundColor===question[3].style.backgroundColor &&answer[12].style.backgroundColor===question[4].style.backgroundColor &&answer[13].style.backgroundColor===question[5].style.backgroundColor && answer[16].style.backgroundColor===question[6].style.backgroundColor && answer[17].style.backgroundColor===question[7].style.backgroundColor && answer[18].style.backgroundColor===question[8].style.backgroundColor){
    highScEasy();
    document.getElementById('win').play();
    swal(" Congratulations!!🥳 | | Clicks You Used:  "+ x +" | | "+ " You time is :  "+ hours + ":" + minutes+":" + seconds+" High score :  " + hs);
    window.clearInterval(timer);  
    }
}
