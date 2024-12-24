// Nút "Không đồng ý" sẽ chạy trốn khi nhấn vào
const noBtn = document.getElementById("no-btn");
noBtn.addEventListener("click", function () {
    const button = this;
    button.style.position = "absolute";
    button.style.top = Math.random() * 80 + "%";
    button.style.left = Math.random() * 80 + "%";
});

// Nút "Đồng ý" hiển thị hiệu ứng đáng yêu
const yesBtn = document.getElementById("yes-btn");
yesBtn.addEventListener("click", function () {
    const effect = document.getElementById("effect");
    effect.innerHTML = `
        <h2>Yay! Em đã tha lỗi cho anh! 😍</h2>
        <img src="https://media.giphy.com/media/3o7abKhOpu0NwenH3O/giphy.gif" alt="celebrate">
    `;
});
