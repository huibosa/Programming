import unittest
from city_functions import city_country


class CityTestCase(unittest.TestCase):
    def test_city_country(self):

        result = city_country("santiago", "chile")
        self.assertEqual(result, "Santiago, Chile")

    def test_city_country_population(self):

        result = city_country("santiago", "chile", "50_000")
        self.assertEqual(result, "Santiago, Chile - Population 50000")


if __name__ == "__main__":
    unittest.main()
