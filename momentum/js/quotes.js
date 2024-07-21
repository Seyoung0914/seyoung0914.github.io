const quotes = [
    {
        quote: '인생은 공평하지 않다. 그러니 그냥 익숙해져라.',
        author: '빌게이츠',
    },
    {
        quote: '인생은 험난한 노정이다. 도전은 그대를 괴롭혀먼지 속에 사라지도록 하는 것이 아니라반짝반짝 윤을 내찬란한 보석이 되게 하는 것이다.',
        author: '존 밀든포그',
    },
    {
        quote: '일련의 작은 것들이 함께 모여 위대한 것을 이룬다.',
        author: '빈센트 반 고흐',
    },
    {
        quote: '인생에는 서두르는 것 말고도 더 많은 것이 있다.',
        author: '마하트마 간디',
    },
    {
        quote: '성공이란 최종적이지 않으며, 실패란 치명적이지 않다. 중요한 것은 계속할 용기다.',
        author: '윈스턴 처칠',
    },
    {
        quote: '인생은 과감한 모험이거나 아무것도 아니다',
        author: '헬렌 켈러',
    },
    {
        quote: '삶을 사는 두 가지 방법이 있다. 하나는 기적이 전혀 없는 것처럼 사는 것이고, 다른 하나는 모든 것이 기적처럼 사는 것이다.',
        author: '앨버트 아인슈타인',
    },
    {
        quote: '가장 지속적인 아름다움은 세상을 변화시키는 것이다.',
        author: '마틴 루터 킹 주니어',
    },
    {
        quote: '당신이 가진 것에 감사하라. 그러면 더 많은 것을 갖게 될 것이다. 당신이 가진 것에 집중하지 않으면, 절대로 충분하지 않을 것이다.',
        author: '오프라 윈프리',
    },
    {
        quote: '내가 숲 속을 걷다가 두 갈래 길을 만났습니다. 나는 덜 걸어간 길을 택했고, 그것이 내 모든 것을 바꾸었습니다.',
        author: '로버트 프로스트',
    },
];

const quote = document.querySelector('#quote span:first-child');
const author = document.querySelector('#quote span:last-child');

const todaysQuote = quotes[Math.floor(Math.random() * quotes.length)];

quote.innerText = todaysQuote.quote;
author.innerText = todaysQuote.author;
