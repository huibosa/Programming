import unittest
from name_function import get_formatted_name


class NameFooTestCase(unittest.TestCase):
    def test_get_first_last_name(self):
        formatted_name = get_formatted_name("hu", "haoran")
        self.assertEqual(formatted_name, "Hu Haoran")

    def test_get_first_last_middle_name(self):
        formatted_name = get_formatted_name("hu", "haoran", "lalala")
        self.assertEqual(formatted_name, "Hu Lalala Haoran")


if __name__ == "__main__":
    unittest.main()
