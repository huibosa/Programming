; two move of n - 1 high tower
; one move of 1 high tower
(define (move n from to spare)
  (cond ((= n 0) "done")
        (else
          (move (-1 + n) from spare to)
          (print move from to)
          (move (-1 + n) spare to from))))

(move 4 1 2 3)
(move 3 1 3 2) ...
(move 2 1 2 3) ...
(move 1 1 3 2) ...
