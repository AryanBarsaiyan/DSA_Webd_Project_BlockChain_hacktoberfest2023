const display = document.getElementById("display");
const hide = document.getElementById("hide");
const inv = "-1";

let historyData = [];
let expressionData = "";
let resultData = "";

let bottom = document.querySelectorAll(".bottom");
let up = document.querySelectorAll(".up");
let button = document.querySelectorAll(".button");

const radian = document.getElementById("rad");
const body = document.getElementById("body");

// Coursor
const el = document.getElementById("display");
const selection = window.getSelection();
const range = document.createRange();
selection.removeAllRanges();
range.selectNodeContents(el);
range.collapse(false);
selection.addRange(range);
el.focus();

// rad/deg
function rad() {
  radian.classList.remove("hide");
  radian.classList.add("unhide");
  setInterval(function () {
    radian.classList.add("hide");
    radian.classList.remove("unhide");
  }, 5000);
}

function rad_deg() {
  if (radian.innerText == "rad") {
    radian.innerText = "deg";
  } else {
    radian.innerText = "rad";
  }
}

// Switch
function show() {
  if (bottom[0].classList.contains("hide") == true) {
    for (i = 0; i <= 11; i++) {
      bottom[i].classList.remove("hide");
      up[i].classList.add("hide");
    }
  } else {
    for (i = 0; i <= 11; i++) {
      bottom[i].classList.add("hide");
      up[i].classList.remove("hide");
    }
  }
}

function back() {
  if (display.innerHTML) {
    display.innerHTML = display.innerText.slice(0, -1);
  }
  if (hide.innerHTML) {
    hide.innerHTML = hide.innerText.slice(0, -1);
  }
}

// sign check
function check() {
  let last = hide.innerText.slice(-1);
  if (last !== "/" || last !== "*" || last !== "-" || last !== "+") {
    if (last == "" || last == "(") {
    } else {
      display.innerHTML += "×";
      hide.innerHTML += "*";
    }
  }
}

// ) bracket check
function bracket_check() {
  let last = hide.innerText.slice(-1);
  if (last == ")") {
    if (last !== "/" || last !== "*" || last !== "-" || last !== "+") {
      if (last == "" || last == "(") {
      } else {
        display.innerHTML += "×";
        hide.innerHTML += "*";
      }
    }
  }
}

// Theme 1
function th1() {
  body.classList.add("th1_body");
  body.classList.remove("th2_body");
  display.classList.add("th1_dis");
  display.classList.remove("th2_dis");
  for (i = 0; i <= 31; i++) {
    button[i].classList.remove("th2_btn");
    button[i].classList.add("th1_btn");
  }
}

// Theme 2
function th2() {
  body.classList.add("th2_body");
  body.classList.remove("th1_body");
  display.classList.add("th2_dis");
  display.classList.remove("th1_dis");
  for (i = 0; i <= 31; i++) {
    button[i].classList.add("th2_btn");
    button[i].classList.remove("th1_btn");
  }
}

// If Error
function equal() {
  if (display.innerHTML == "Error") {
    display.innerHTML = "";
  }
}

// Main Function of Calculator
const switch_button = (e) => {
  switch (e.target.innerText) {
    case "C":
      display.innerHTML = "";
      hide.innerHTML = "";
      break;
    case "=":
      try {
        console.log(hide.innerText);
        display.innerText = eval(hide.innerText).toFixed(2);
        // history
        expressionData = hide.innerText;
        resultData = display.innerText;
        historyData.push({ expression: expressionData, result: resultData });
        showHistory();
        expressionData = "";
        resultData = "";
        // <---->
        if (display.innerHTML == "NaN") {
          display.innerHTML = "Error";
          hide.innerHTML = "";
        }
      } catch {
        display.innerHTML = "Error";
        hide.innerHTML = "";
      }
      break;
    case "←":
      break;
    case "÷":
      {
        display.innerHTML += "÷";
        hide.innerHTML += "/";
      }
      break;
    case "×":
      {
        display.innerHTML += "×";
        hide.innerHTML += "*";
      }
      break;
    case "−":
      {
        display.innerHTML += "-";
        hide.innerHTML += "-";
      }
      break;
    case "+":
      {
        display.innerHTML += "+";
        hide.innerHTML += "+";
      }
      break;
    case "sin":
      {
        bracket_check();
        check();
        rad();
        display.innerHTML += "Sin(";
        if (radian.innerText == "rad") {
          hide.innerHTML += "Math.sin(";
        } else {
          hide.innerHTML += "Math.sin((Math.PI/180)*";
        }
      }
      break;
    case "cos":
      {
        bracket_check();
        check();
        rad();
        display.innerHTML += "Cos(";
        if (radian.innerText == "rad") {
          hide.innerHTML += "Math.cos(";
        } else {
          hide.innerHTML += "Math.cos((Math.PI/180)*";
        }
      }
      break;
    case "tan":
      {
        bracket_check();
        check();
        rad();
        display.innerHTML += "Tan(";
        if (radian.innerText == "rad") {
          hide.innerHTML += "Math.tan(";
        } else {
          hide.innerHTML += "Math.tan((Math.PI/180)*";
        }
      }
      break;
    case "sin-1":
      {
        bracket_check();
        check();
        rad();
        display.innerHTML += "Sin" + inv.sup() + "(";
        if (radian.innerText == "rad") {
          hide.innerHTML += "Math.asin(";
        } else {
          hide.innerHTML += "(180/Math.PI)*Math.asin(";
        }
      }
      break;
    case "cos-1":
      {
        bracket_check();
        check();
        rad();
        display.innerHTML += "Cos" + inv.sup() + "(";
        if (radian.innerText == "rad") {
          hide.innerHTML += "Math.acos(";
        } else {
          hide.innerHTML += "(180/Math.PI)*Math.acos(";
        }
      }
      break;
    case "tan-1":
      {
        bracket_check();
        check();
        rad();
        display.innerHTML += "Tan" + inv.sup() + "(";
        if (radian.innerText == "rad") {
          hide.innerHTML += "Math.atan(";
        } else {
          hide.innerHTML += "(180/Math.PI)*Math.atan(";
        }
      }
      break;
    case "ln":
      {
        bracket_check();
        check();
        display.innerHTML += "ln(";
        hide.innerHTML += "Math.log(";
      }
      break;
    case "log":
      {
        bracket_check();
        check();
        display.innerHTML += "log(";
        hide.innerHTML += "(1/2.302585092994046)*Math.log(";
      }
      break;
    case "π":
      {
        bracket_check();
        check();
        display.innerHTML += "π";
        hide.innerHTML += "Math.PI";
      }
      break;
    case "e":
      {
        bracket_check();
        check();
        display.innerHTML += "e";
        hide.innerHTML += "Math.E";
      }
      break;
    case "√":
      {
        bracket_check();
        check();
        display.innerHTML += "√(";
        hide.innerHTML += "Math.sqrt(";
      }
      break;
    case "∛":
      {
        bracket_check();
        check();
        display.innerHTML += "∛(";
        hide.innerHTML += "Math.cbrt(";
      }
      break;
    case "(":
      {
        bracket_check();
        check();
        display.innerHTML += "(";
        hide.innerHTML += "(";
      }
      break;
    default:
      bracket_check();
      display.innerHTML += e.target.innerHTML;
      hide.innerHTML += e.target.innerHTML;
  }
};

// History adder
function showHistory() {
  let log = document.getElementById("history_log");
  let string = "";
  for (let key in historyData) {
    string +=
      "" +
      historyData[key]["expression"] +
      " = " +
      historyData[key]["result"] +
      "<br>" +
      "<br>";
  }
  log.innerHTML = string;
}

// History Viewer
function historyView() {
  if (
    document.getElementById("history_log").classList.contains("hide") == true
  ) {
    document.getElementById("history_log").classList.remove("hide");
    document.getElementById("calculator").classList.add("hide");
    body.classList.remove("body_block");
  } else {
    document.getElementById("history_log").classList.add("hide");
    document.getElementById("calculator").classList.remove("hide");
    body.classList.add("body_block");
  }
}

// Buttons Funx
let buttons = Array.from(document.getElementsByClassName("button"));

buttons.map((button) => {
  button.addEventListener("click", (e) => {
    equal();
    switch_button(e);
  });
});
