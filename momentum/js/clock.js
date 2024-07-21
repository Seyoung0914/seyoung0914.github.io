const clock = document.querySelector('h2#clock');

function getClcok() {
    const date = new Date();
    const hour = date.getHours().toString().padStart(2, '0');
    const minutes = date.getMinutes().toString().padStart(2, '0');
    const seconds = date.getSeconds().toString().padStart(2, '0');

    clock.innerText = `${hour}:${minutes}:${seconds}`;
}
getClcok();
setInterval(getClcok, 1000);
