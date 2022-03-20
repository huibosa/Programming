; Exercise 1.3: Deﬁne a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers.

(define (get_bigger_sum_of_square a b c)
  (define (square x)
    (* x x))
  (define (sum_of_suqare x y)
    (+ (square x) (square y)))
  
  (cond (((and (> a b) (> b c)) (sum_of_suqare a b)))
        (((and (> c b) (> b a)) (sum_of_suqare b c)))
        (((and (> a c) (> c b)) (sum_of_suqare a c)))
        (else (sum_of_suqare a b))))
