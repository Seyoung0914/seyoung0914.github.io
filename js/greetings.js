const loginForm = document.getElementById('login-form');
const loginInput = loginForm.querySelector('input');
const greeting = document.querySelector('#greeting');

const HIDDEN_CLASSNAME = 'hidden';
const USERNAME_KEY = 'username';

function handleSubmitValue(event) {
    event.preventDefault();

    const username = loginInput.value;

    localStorage.setItem(USERNAME_KEY, username);

    loginForm.classList.add(HIDDEN_CLASSNAME);

    paintGreetings();
}

function paintGreetings() {
    savedUserName = localStorage.getItem(USERNAME_KEY);
    const username = savedUserName;
    greeting.innerText = `Hello ${username}`;
    greeting.classList.remove(HIDDEN_CLASSNAME);
}

savedUserName = localStorage.getItem(USERNAME_KEY);

if (savedUserName === null) {
    loginForm.classList.remove(HIDDEN_CLASSNAME);
    loginForm.addEventListener('submit', handleSubmitValue);
} else {
    paintGreetings();
}
