const colors=['#dc143c','#00ffff','#008000','#800080','#ffa500','#ffff00'];
const colors2=document.querySelectorAll('.item');
const colors3=document.querySelectorAll('.box');
let colors4=[];

for(let i=0; i<colors2.length;i++){
  let colorGrid=colors[Math.floor(Math.random()*6)];
  colors2[i].style.backgroundColor=colorGrid;
  colors4.push(colorGrid);
}

for(let i=0;i<10;i++){
  colors3[i].style.backgroundColor=colors4[i];
}

do{
  var randomNum=Math.floor(Math.random()*25);
}

while(randomNum<10);
for(let i=9;i<colors3.length;i++){
  if(randomNum===i){
    continue;
  }
  colors3[i].style.backgroundColor= colors[Math.floor(Math.random()*6)];
}

function movementMechanism(swap){
  let swapElement=document.getElementById(swap);
  let swapUp=document.getElementById(String(+swap+5));
  let swapDown=document.getElementById(String(+swap-5));
  let swapRight=document.getElementById(String(+swap+1));
  let swapLeft=document.getElementById(String(+swap-1));
  if(swapUp  && swapUp.style.backgroundColor==""){
     swapUp.style.backgroundColor=swapElement.style.backgroundColor;
    swapElement.style.backgroundColor="";
  }
  else if(swapDown && swapDown.style.backgroundColor==""){
     swapDown.style.backgroundColor=swapElement.style.backgroundColor;
    swapElement.style.backgroundColor="";
  }
  else if(swapRight && swapRight.style.backgroundColor==""){
     swapRight.style.backgroundColor=swapElement.style.backgroundColor;
    swapElement.style.backgroundColor="";
  }
  else if(swapLeft &&swapLeft.style.backgroundColor==""){
     swapLeft.style.backgroundColor=swapElement.style.backgroundColor;
    swapElement.style.backgroundColor="";
  }

}

