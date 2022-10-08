let storageHard = localStorage.getItem('highScoreHard');

function highScHard(){
  if(storageHard!==null){
    if(x<parseInt(storageHard)){
      localStorage.setItem('highScoreHard',x);
    }
  }
  else{
    localStorage.setItem('highScoreHard',x);
  }
  hd=localStorage.getItem('highScoreHard');
}


function answer2(){
  const question = document.querySelectorAll('.item');
  const answer = document.querySelectorAll('.box');

  if(question && answer && answer[7].style.backgroundColor===question[0].style.backgroundColor && answer[8].style.backgroundColor===question[1].style.backgroundColor && answer[9].style.backgroundColor===question[2].style.backgroundColor && answer[10].style.backgroundColor===question[3].style.backgroundColor &&answer[13].style.backgroundColor===question[4].style.backgroundColor &&answer[14].style.backgroundColor===question[5].style.backgroundColor && answer[15].style.backgroundColor===question[6].style.backgroundColor && answer[16].style.backgroundColor===question[7].style.backgroundColor && answer[19].style.backgroundColor===question[8].style.backgroundColor  && answer[20].style.backgroundColor===question[9].style.backgroundColor  && answer[21].style.backgroundColor===question[10].style.backgroundColor  && answer[22].style.backgroundColor===question[11].style.backgroundColor  && answer[25].style.backgroundColor===question[12].style.backgroundColor  && answer[26].style.backgroundColor===question[13].style.backgroundColor  && answer[27].style.backgroundColor===question[14].style.backgroundColor  && answer[28].style.backgroundColor===question[15].style.backgroundColor){
    highScHard();
    document.getElementById('win').play();
    swal(" Congratulations!!🥳 | | Clicks You Used:  "+ x +" | | "+ " You time is :  "+ hours + ":" + minutes+":" + seconds+" High Score:  " + hd);
    window.clearInterval(timer);  
    }
}