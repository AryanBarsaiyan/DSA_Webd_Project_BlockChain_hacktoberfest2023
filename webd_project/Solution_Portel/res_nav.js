burger = document.querySelector('.burger');
list = document.querySelector('.li');
list1 = document.querySelector('.li1');
list2 = document.querySelector('.li2');
list3 = document.querySelector('.li3');
list4 = document.querySelector('.li4');
list = document.querySelector('.li5');
ul = document.querySelector('.ul')

burger.addEventListener('click',()=>{
  ul.classList.toggle('h-res');
  list.classList.toggle('res');
  list1.classList.toggle('res');
  list2.classList.toggle('res');
  list3.classList.toggle('res');
  list4.classList.toggle('res');
  list5.classList.toggle('res');
})