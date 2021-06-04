
window.onload = function() {
    a = document.getElementById('a');
    a.style.right = '-400px';
    move();
}

function move() {
    if (parseInt(a.style.right) > (innerWidth))
        a.style.right = 0;
        a.style.right = parseInt(a.style.right) + 15 + 'px';
        setTimeout(move,200);
}