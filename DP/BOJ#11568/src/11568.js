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
let n = 0;
let arr = [];
let dpF = [];


function solve(idx){
  if(idx >= arr.length)
    return 0;
  if(dpF[idx] != -1) return dpF[idx];

  dpF[idx] = 0;
  for(let i =idx+1; i < arr.length; i++){
    if(arr[i] > arr[idx])
      dpF[idx] = Math.max(dpF[idx], solve(i)+1);
  }

  return dpF[idx];
}


rl.on('line', (line) => {
  input.push(line.trim());
}).on('close', () => {
  n = input.shift();
  arr = input.shift().split(' ').map((a) => parseInt(a));

  dpF = Array(arr.length).fill(-1)

  let ans = 0;
  for(let i = 0; i < arr.length; i++){
    ans = Math.max(solve(i), ans);

  }

  console.log(ans+1)
  process.exit();
});