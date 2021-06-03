const readline = require('readline');
const fs = require('fs');
const path = require("path");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// const rl = readline.createInterface({
//     input: fs.createReadStream(path.resolve(__dirname, ".main.js/in.txt")),
// });


let input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {



    process.exit();
});