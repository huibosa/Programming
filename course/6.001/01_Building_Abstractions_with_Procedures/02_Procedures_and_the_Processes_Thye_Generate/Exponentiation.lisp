; recursion process
(define (expt b n)
  (if (= n 0)
      1
      (* b (expt b (- n 1)))))

; fast exponentiation (recursion process)
; O(logn) in time and space
(define (fast-expt b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt b (/ n 2))))
        (else (* b (fast-expt b (- n 1))))))
(define (even? n)
  (= (remainder n 2) 0)) ; primitive procedure `remainder`

; iterative process 1
(define (expt b n)
  (iter b n 1))
(define (iter b counter product)
  (if (= counter 0)
      product
      (iter b (- counter 1) (* b product))))

; iterative process 2
(define (expt x n)
  (define (iter product counter)
    (if (= counter n)
        product
        (iter (* product x) (+ counter 1))))
  (iter x 1))
