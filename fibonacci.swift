func fib(_ num: Int) -> Int {
   switch num {
     case Int.min...1: return max(0, num)
     default: return fib(num-2) + fib(num-1)
   }
}

let sequence = Array(0...10)
sequence.forEach { print(fib($0)) } // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
