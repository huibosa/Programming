; recursive process
(define (foo n)
  (if (< n 3)
      n
      (+ (foo (- n 1) (* 2 (foo (- n 2))) (* 3 (foo (- n 3)))))))

; iterative process 1
(define (foo n)
  (if (< n 3)
      n
      (foo-iter 2 1 0 n)))

(define (foo-iter a b c count)
  (if (< count 3)
      a
      (foo-iter (+ a (* 2 b) (* 3 c))
                a
                b
                (- count 1))))
