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
let f, start, goal, u ,d;

const bfs = () => {
    let visited = Array.from({length: f+1}, (e, i) => false);
    let q = [];
    q.push([start, 0]);
    visited[start] = true;

    while(q.length !== 0){
        let [floor, cnt] = q.shift();
        if(floor === goal)
            return cnt;

        let newUpFloor = floor+u;
        if(newUpFloor <= f && !visited[newUpFloor]){
            visited[newUpFloor] = true;
            q.push([newUpFloor, cnt+1]);
        }
        let newDonwFloor = floor-d;
        if(newDonwFloor >= 1 && !visited[newDonwFloor]){
            visited[newDonwFloor] = true;
            q.push([newDonwFloor, cnt+1]);
        }
    }
    return -1;
}
rl.on('line', (line) => {
    input.push(line.trim());
}).on('close', () => {
    [f, start, goal, u ,d] = input.shift().split(' ').map(e => parseInt(e));

    let ret = bfs();
    if(ret === -1)
        console.log('use the stairs')
    else
        console.log(ret)
    process.exit();
});