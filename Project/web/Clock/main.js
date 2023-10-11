// -------------------------- CLOCK ------------------------------//
const hour=document.getElementById('clock-hour'),
    mins=document.getElementById('clock-min'),
    secs=document.getElementById('clock-sec')

const clock=()=>{
    let date=new Date()
    let h=date.getHours()*30,
        min = date.getMinutes() * 6,
        sec = date.getSeconds() * 6
    
    // Rotation to elements
    hour.style.transform=`rotateZ(${h+min/12}deg)`
    mins.style.transform=`rotateZ(${min}deg)`
    secs.style.transform=`rotateZ(${sec}deg)`
}

setInterval(clock, 1000) // 1000=1s

// -------------------------- DATE ------------------------------//
const texthr=document.getElementById('text-hr'),
    textmin=document.getElementById('text-min'),
    textam=document.getElementById('text-am'),
    dateDay=document.getElementById('date-day'),
    dateMonth=document.getElementById('date-month'),
    dateYear=document.getElementById('date-year')

const Text= ()=>{
    let date=new Date()
    let h=date.getHours(),
    am,
    min=date.getMinutes(),
    day=date.getDate(),
    month=date.getMonth(),
    year=date.getFullYear()

    if(h>=12){
        am='PM'
    }
    else{
        am='AM'
    }
    if(h<10){h=`0${h}`}

    texthr.innerHTML=`${h}:`

    if(min<10){min=`0${min}`}

    textmin.innerHTML=min

    textam.innerHTML=am

    let months=['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sept','Oct','Nov','Dec']

    dateDay.innerHTML=day
    dateMonth.innerHTML=`${months[month]},`
    dateYear.innerHTML=year
    
    //For 12 hr format
    // if(h>=12){
    //     h=h-12
    //     am='PM'
    // }
    // else{
    //     am='AM'
    // }
    // if(h==0){h=12}
}
setInterval(Text,1000)//1000=1s

// ----------------------- DARK MODE-------------------------------//
const themeButton = document.getElementById('theme-btn')
const darkTheme = 'dark-theme'
const iconTheme = 'bxs-sun'

const selectedTheme = localStorage.getItem('selected-theme')
const selectedIcon = localStorage.getItem('selected-icon')

const getCurrentTheme = () => document.body.classList.contains(darkTheme) ? 'dark' : 'bxs-moon'
const getCurrentIcon = () => themeButton.classList.contains(iconTheme) ? 'bxs-moon' : 'bxs-sun'

if (selectedTheme) {
    document.body.classList[selectedTheme === 'dark' ? 'add' : 'remove'](darkTheme)
    themeButton.classList[selectedIcon === 'bxs-moon' ? 'add' : 'remove'](iconTheme)
}

// Activate / deactivate the theme manually with the button
themeButton.addEventListener('click', () => {
    document.body.classList.toggle(darkTheme)
    themeButton.classList.toggle(iconTheme)
    localStorage.setItem('selected-theme', getCurrentTheme())
    localStorage.setItem('selected-icon', getCurrentIcon())
})