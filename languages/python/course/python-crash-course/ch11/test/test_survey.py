import unittest
from survey import AnonymousSurvey


class AnonymousSurveyTestCase(unittest.TestCase):
    def setUp(self):
        question = "What is your favorite language?"
        self.my_survey = AnonymousSurvey(question)
        self.response = ["English", "Spanish", "Madarin"]

    def test_store_single(self):
        self.my_survey.store_response(self.response[0])
        self.assertIn("English", self.my_survey.responses)

    def test_store_multiple(self):
        for response in self.response:
            self.my_survey.store_response(response)

        for response in self.response:
            self.assertIn(response, self.my_survey.responses)


if __name__ == "__main__":
    unittest.main()
