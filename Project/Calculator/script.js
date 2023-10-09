let string = "";
let buttons = document.querySelectorAll('.buttons');
let input = document.getElementById('input');

Array.from(buttons).forEach((button) => {
    button.addEventListener('click', (e) => {
        if (e.target.innerHTML === '=') {
            evaluate();
        } else if (e.target.innerHTML === 'C') {
            string = '';
            input.value = string; // Clear the input field
        } else if (e.target.innerHTML === 'cut') {
            string = string.slice(0, -1);
            input.value = string; // Update the input field
        } else {
            string += e.target.innerHTML;
            input.value = string; // Update the input field
        }
    });
});

function dark() {
    document.body.classList.toggle("dark");
    let button = document.getElementById("btn-mode");
    if (button.innerHTML === "Light mode") {
        button.innerHTML = "Dark mode";
    } else {
        button.innerHTML = "Light mode";
    }
}

document.addEventListener('keydown', function (event) {
    const keyPressed = event.key;

    if (/[0-9]/.test(keyPressed)) {
        string += keyPressed;
        input.value = string; 
    } else if (/[\+\-\*\/]/.test(keyPressed)) {
        string += keyPressed;
        input.value = string; 
    } else if (keyPressed === 'Enter') {
        evaluate();
    } else if (keyPressed === 'Backspace') {
        deleteLastCharacter();
    }
});

function evaluate() {
    if (string) {
        string = eval(string).toString(); 
        input.value = string; 
    }
}

function deleteLastCharacter() {
    string = string.slice(0, -1); 
    input.value = string;
  }
