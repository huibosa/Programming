; Exercise 1.5: Ben Bitdiddle has invented a test to determine
; whether the interpreter he is faced with is using applicative-
; order evaluation or normal-order evaluation. He deﬁnes the
; following two procedures:

(define (p) (p))
(define (test x y)
  (if (= x 0) 0 y))

; Then he evaluates the expression

(test 0 (p))

; What behavior will Ben observe with an interpreter that
; uses applicative-order evaluation? What behavior will he
; observe with an interpreter that uses normal-order evalu-
; ation? Explain your answer. (Assume that the evaluation
; rule for the special form if is the same whether the in-
; terpreter is using normal or applicative order: e predi-
; cate expression is evaluated ﬁrst, and the result determines
; whether to evaluate the consequent or the alternative ex-
; pression.)
; 1.1.7 Example: Square Roots by Newton’s Method
; Procedures, as introduced above, are much like ordinary mathemati
