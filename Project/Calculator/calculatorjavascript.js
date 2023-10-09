

function writeNumber(char){
document.getElementById("result").value +=char;
}
function calculate(){

    const equation= document.getElementById("result").value;
    const calculatedResult = eval(equation);
    clearScreen();
    document.getElementById("result").value =calculatedResult;
 }
function clearScreen(){
    document.getElementById("result").value=" ";
}

function del(){
    document.getElementById("result").value=document.getElementById("result").value.slice(0,-1);

}