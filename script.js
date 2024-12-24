// script.js
document.getElementById("no-btn").addEventListener("mouseover", function() {
    const button = this;
    button.style.position = "absolute";
    button.style.top = Math.random() * 80 + "%";
    button.style.left = Math.random() * 80 + "%";
  });
  
  document.getElementById("yes-btn").addEventListener("click", function() {
    const effect = document.getElementById("effect");
    effect.innerHTML = `<h2>Yay! Tmy cute số 1 lun nè ! 😍</h2>`;
    effect.innerHTML += `<img src="https://media.giphy.com/media/3o7abKhOpu0NwenH3O/giphy.gif" alt="celebrate" width="200">`;
  });
  