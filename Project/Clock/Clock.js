
 function rotateclock(){

   const date=new Date();
   const hourHand=document.querySelector(".hour-arm");
    const minuteHand=document.querySelector(".minute-arm");
    const secondHand=document.querySelector(".second-arm");

    if(!hourHand || !secondHand || !minuteHand){
      alert("There is something missing in .html");
      return;
    }
    else{
    const second=date.getSeconds();
    const minute=date.getMinutes();
   const hour=date.getHours();
   const secondDeg=(second / 60) * 360;
    const minuteDeg=((minute*60 +second)/3600)*360;
    const hourDeg=((hour*3600+minute*60 + second)/43200)*360;
   secondHand.style.transform=`rotate(${secondDeg}deg)`;
   minuteHand.style.transform=`rotate(${minuteDeg}deg)`;
   hourHand.style.transform=`rotate(${hourDeg}deg)`;
   requestAnimationFrame(rotateclock);
  //  setInterval(rotateclock,1000);
  }
}

  rotateclock();

 
