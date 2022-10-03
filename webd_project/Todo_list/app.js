todo__list = document.querySelector(".todo__list");
new__form = document.querySelector(".new__form");
new__submit = document.querySelector(".new__submit");
const date = new Date().toLocaleString();

function addTodos(e) {
  e.preventDefault();
  txt = new__form.new_text.value.trim();
  html = `
        <li class="todo__item">
            <span class="todo__icon-tick material-icons">check_box_outline_blank</span>
            <span class="todo__text">${txt}</span>
            <span style="font-size:17px">${date}</span>
            <span class="todo__icon-delete material-icons">delete_outline</span>
        </li>
    `;
  if (txt.length > 0) {
    todo__list.innerHTML += html;
    new__form.reset();
  }
}

function deleteTodos(e) {
  if (e.target.className.includes("todo__icon-delete")) {
    e.target.parentElement.remove();
  }
}
function markDone(e) {
  if (e.target.classList.contains("todo__item")) {
    todo__item = e.target;
  } else {
    todo__item = e.target.parentElement;
  }
  todo__item.classList.toggle("done");
  if (todo__item.classList.contains("done")) {
    todo__item.querySelector(".todo__icon-tick").innerHTML = "check_box";
    todo__item.querySelector(".todo__text").classList.add("cross-out");
  } else {
    todo__item.querySelector(".todo__icon-tick").innerHTML =
      "check_box_outline_blank";
    todo__item.querySelector(".todo__text").classList.remove("cross-out");
  }
}

todo__list.addEventListener("click", deleteTodos);
todo__list.addEventListener("click", markDone);
new__form.addEventListener("submit", addTodos);
new__submit.addEventListener("click", addTodos);
