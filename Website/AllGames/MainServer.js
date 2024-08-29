
export const Data = {
    MyObj:{
        jump:0
    }
}

export const PaddleData = {
    Data:{
        data:0
    }
}


// let dataElement  = document.getElementById("dataID")
let connectionElement  = document.getElementById("serverConnection")

const ws = new WebSocket('ws://192.168.48.56:81');

ws.onopen = function() {
    console.log('Connected to ESP32 WebSocket server');
    connectionElement.innerText = '🟢'
    connectionElement.title = 'Connected to ESP32 WebSocket server'

};

ws.onmessage = function(event) {
    console.log('Message from ESP32:', event.data);
    // Data.MyObj.jump = event.data.trim()
    // if (event.data.trim() === '1') {
    //     Data.MyObj.jump = 1;        
    // }else{
    //     Data.MyObj.jump = 0
    // }
    // dataElement.textContent = `${Data.MyObj.jump}`

    PaddleData.Data.data = event.data.trim()
    
};

ws.onclose = function() {
    console.log('Disconnected from ESP32 WebSocket server');
    connectionElement.innerText = '🔴'
    connectionElement.title = 'Disconnected from ESP32 WebSocket server'
};

ws.onerror = function(error) {
    console.log('WebSocket Error:', error);
    connectionElement.innerText = '⚠️'
    connectionElement.title = `WebSocket Error:- ${error}`
};


// function sendDragonGameData(event) {
//     event.preventDefault(); 

//     if (ws.readyState === WebSocket.OPEN) {
//         ws.send("DragonGame"); 
//         console.log(`Sent: DragonGame`);
//     } else {
//         console.log('WebSocket is not open');
//     }

    
//     setTimeout(() => {
//         window.location.href = event.target.href; 
//     }, 100); 
// }

// function sendPaddleData(){

//     const pathname = window.location.pathname;
//     console.log(pathname);

//     if (ws.readyState === WebSocket.OPEN) {
//         ws.send("PaddleGame"); 
//         console.log(`Sent: PaddleGame`);
//     } else {
//         console.log('WebSocket is not open');
//     }

// }

// document.getElementById('PaddleGame').addEventListener('click', sendPaddleData);
// document.getElementById('DragonGame').addEventListener('click', sendDragonGameData);


// const pathname = window.location.pathname;
// console.log(pathname);







