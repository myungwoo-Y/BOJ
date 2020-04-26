const readline = require('readline');
const fs = require('fs');
const path = require("path");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


// const rl = readline.createInterface({
//     input: fs.createReadStream(path.resolve(__dirname, "in.txt")),
// });

let input = [];
let n = 0;
let arr = [];
let dp = [];
let maxSum = 0;
function cal(newArr){
    let sum = 0;
    for(let i = 1; i < newArr.length; i++){
        sum += Math.abs(newArr[i] - newArr[i-1]);
    }
    maxSum = Math.max(sum, maxSum)
}

function permutation(idx, visited, newArr){
    if(newArr.length == n){
        cal(newArr);
        return;
    }

    for (let i = 0; i < arr.length; i++){
        visited[idx] = true;
        if(!visited[i]){
            newArr.push(arr[i]);
            permutation(i, visited, newArr);
            newArr.pop();
        }
        visited[idx] = false;
    }
}

rl.on('line', (line) => {
    input.push(line.trim());
}).on('close', () => {
    n = input.shift();
    arr = input.shift().split(' ').map((a) => parseInt(a));
    let visited = Array(arr.length).fill(false);
    let newArr = []
    for(let i = 0; i < n; i++){
        newArr.push(arr[i]);
        permutation(i, visited, newArr);
         newArr.pop();
    }
    console.log(maxSum);
    process.exit();
});