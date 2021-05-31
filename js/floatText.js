
window.onload = function() {
    a = document.getElementById('a');
    a.style.right = '-400px';
    b();
}

function b() {
    if (parseInt(a.style.right) > (innerWidth))
        a.style.right = 0;
        a.style.right = parseInt(a.style.right) + 15 + 'px';
        setTimeout(b,200);
}

var ball = document.getElementById('ball');
var x = 0
  , y = 0;
var width = 20 
  , height = 20;
var width_ = innerWidth 
  , height_ = innerHeight;

function bb() {
    x = x + width;
    y = y + height;

    if (x > width_ - 220 || x < 1)  width = -width;
    if (y > height_ - 220 || y < 1) height = -height;
    
    ball.style.left = x + 'px';
    ball.style.top =  y + 'px';
}

setInterval(bb,10);
