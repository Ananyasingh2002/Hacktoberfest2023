const output = document.getElementById('generated_pwd')
document.getElementById('copy').addEventListener('click',copy)
function generate_pwd(event) {
    const length = 10,
        charset =
        'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,;:!?./>>#{[|^@]}&'
        var pwd = ''
        for (var i=0, n=charset.length; i<length; ++i) {
            pwd +=charset.charAt(Math.floor(Math.random()*n))
        }
        output.innerHTML = pwd
}
function copy(){
    const copyText = output.innerHTML
    navigator.clipboard.writeText(copyText).then(()=>{
        alert('Copied to clipboard :'+copyText)
    })
}