; We have many coins, but each coin is either 1, 5, 10, 25 or 50 cents, in total
; 5 kinds of coins. We need to buy something for a dollar, 100 cents. Assume
; unlimited supply of each kind of coins. How many ways are there for us to
; reach the total sum of 100?
(define (count-change amount) (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount (- kinds-of-coins 1))
                 (cc (- amount (first-denomination kinds-of-coins)) kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

(count-change 10)
(cc 3 5)
