; iterative process
(define (fib n)
  (define (fib-iter a b count)
    (if (= count 0)
        b
        (fib-iter a (+ a b) (- count 1))))
  (fib-iter 0 1 n))

; recursion process
; time = (fib(n)))
; space = O(n)
(define (fib n)
  (if (< n 2)
    n
    (+ (fib (- n 1))
       (fib (- n 2)))))

(define (fib n)
  (cond ((= n 0) 1)
        ((= n 1) 1)
        (else (+ (fib (- n 2) (- n 1))))))
