function checkBreak():void{
    let item:i32;
    for (let idx:i32=0; idx < 32; ++idx) {
        if (idx == 12) { 
            item = idx + 32;
            break;
        }
    }
    assert(item == 32);
}
checkBreak();