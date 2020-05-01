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


let start, p;
let input = [];
let counts = new Array(300000).fill(-1);

const sumDigit = (str) => {
    let sum = 0;
    for(let i = 0; i < str.length; i++){
       sum += Math.pow(parseInt(str[i]), p);
    }
    return sum;
}


rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    [start, p] = input.shift().split(' ').map(e => parseInt(e));

    let cur = String(start);
    let sum = 0;
    let cnt = 1;
    counts[start] = 1;
    while(true){
        cnt++;
        sum = sumDigit(cur);
        if(counts[sum] !== -1){
            console.log(counts[sum]-1);
            break;
        }else{
            counts[sum] = cnt;
        }
        cur = String(sum);
    }

    process.exit();
});