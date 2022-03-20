(define abs
    (cond ((< x 0) (- x))
          ((= x 0 0))
          ((> x 0 x))))

(define abs
    (cond ((< x 0) (- x))
          (else x)))

(define abs
    (if (< x 0)
        (- x)
        x))
