const readline = require('readline');
const fs = require('fs');
const path = require("path");

// const rl = readline.createInterface({
//   input: process.stdin,
//   output: process.stdout
// });

const rl = readline.createInterface({
  input: fs.createReadStream(path.resolve(__dirname, "../..//in.txt")),
});
 

let input = [];
 
rl.on('line', (line) => {
    input = line.split(' ').map((el) => parseInt(el));
}).on('close', () => {
    console.log(input[0] - input[1]);
    process.exit();
});