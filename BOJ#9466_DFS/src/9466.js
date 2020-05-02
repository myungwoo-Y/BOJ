const readline = require('readline');
const fs = require('fs');
const path = require("path");

// const rl = readline.createInterface({
//   input: process.stdin,
//   output: process.stdout
// });

const rl = readline.createInterface({
    input: fs.createReadStream(path.resolve(__dirname, "./in.txt")),
});


const checkCycle = (v, start, visited, seq) => {
    if(v === start){
        visited.forEach((e,i)=>{
            if(e){
                isCycle[i] = true;
                cnt++;
            }
        });
        return;
    }else if(visited[v] && v !== start){
        visited[start] = true;
        return;
    }

    visited[v] = true;
    checkCycle(arr[v-1], start, visited);
}
let cnt = 0;
let input = [];
let n = 0;
let arr = [];
let graph = [];
let isCycle = [];
rl.on('line', (line) => {
    input.push(line)
}).on('close', () => {
    let testCase = parseInt(input.shift());

    for(let z = 0; z < testCase; z++){
        cnt = 0;
        n = parseInt(input.shift());
        arr = input.shift().split(' ').map(e => parseInt(e));
        graph = new Array(n+1).fill(new Array(n+1).fill(false));
        isCycle = new Array(n+1).fill(false);
        for(let i = 0; i < arr.length; i++){
            graph[i+1][arr[i]] = true;
        }

        for(let i = 0; i < arr.length; i++){
            if(!isCycle[i+1]){
                let visited = new Array(n+1).fill(false);
                visited[i+1] = true;
                checkCycle(arr[i], i+1, visited);
            }
        }
        console.log(n-cnt);
    }

    process.exit();
});