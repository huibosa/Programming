import unittest
from employee import Employee


class EmployeeTestCase(unittest.TestCase):
    def setUp(self):
        self.huibosa = Employee("hu", "haoran", 6_000)

    def test_give_default_raise(self):
        self.huibosa.give_raise()
        self.assertEqual(self.huibosa.salary, 11000)

    def test_give_raise(self):
        self.huibosa.give_raise(10_000)
        self.assertEqual(self.huibosa.salary, 16000)


if __name__ == "__main__":
    unittest.main()
