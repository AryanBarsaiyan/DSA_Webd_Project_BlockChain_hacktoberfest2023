var main = document.getElementById("main");
var result = document.getElementById("result");
var usr = 'X';
var bot = '0';
var gameOver = false;
var cellIDs=[];
var botMove = false;
var patterns = [[1,2,3,4],[1,6,11,16],[1,5,9,13],[2,6,10,14],[3,7,11,15],[4,8,12,16],[4,7,10,13],[5,6,7,8],[9,10,11,12],[13,14,15,16]];
var cells = function(i){
	return `<div class ="cells" id = "cell${i}" data-value="${i}" onclick="cellClick(this)"></div>`
}

for(var i=1;i<17;i++){
	main.innerHTML+=cells(i);
	cellIDs.push(i);
}

function cellVal(id){
	var elemVal = document.getElementById('cell'+id).innerHTML;
	return elemVal
}

async function checkPos(){
	for(var i = 0;i<patterns.length;i++){
		if(cellVal(patterns[i][0])!='' && cellVal(patterns[i][0])==cellVal(patterns[i][1]) && cellVal(patterns[i][1])==cellVal(patterns[i][2]) && cellVal(patterns[i][2])==cellVal(patterns[i][3])){
			await won(i);
			break
		}else {
		}
	}
	if(cellIDs.length==0 && !gameOver){
		won(-1);
	}}

async function won(i){
	gameOver=true;
	var allCells = document.querySelectorAll('.cells');
	for(var p=0;p<allCells.length;p++){
		allCells[p].style.pointerEvents='none';		
	}
	result.style.display='flex';
	if (i== -1){
		result.innerText='Draw!';
	}
	else{
		for(var p=0;p<4;p++){
			document.getElementById('cell'+patterns[i][p]).style.background=" #03CC90";
		}
		result.innerText=cellVal(patterns[i][0])+' wins!';
	}
}
function reset(){
	var allCells = document.querySelectorAll('.cells');
	for(var p=0;p<16;p++){
		allCells[p].style.pointerEvents='auto';		
		allCells[p].innerHTML='';		
		allCells[p].style.background='#C7E4E8';		
	}
	cellIDs=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16];
	botMove=false;
	gameOver=false;
	result.innerHTML='X to Move';
}

function botMoves(){
	if(cellIDs.length!=0 && !gameOver){
		var id = (cellIDs[Math.floor(Math.random()*(cellIDs.length-1))]);
		document.getElementById('cell'+ id).innerHTML=bot;
		cellIDs = cellIDs.filter(item => item != id);
		botMove=false;
		result.innerHTML='X to Move';
		checkPos();
	}
}
async function cellClick(e){
	if(!botMove && e.innerHTML=='' ){
		e.innerHTML=usr;
		result.innerHTML='0 to Move';
		cellIDs = await cellIDs.filter(item => item != e.getAttribute('data-value'));
		botMove=true;
		await checkPos();
		await	botMoves();
	}
}


