(define (try guess x)
  (if (good_enough guess x)
  guess
  (try (improve guess x) x)))

(define (sqrt x))(try 1 x)

(define (improve guess x)
  (average guess (/ x guess)))

(define (good_enough guess x)
  (< (abs (- (square guess) x))
     .001))
