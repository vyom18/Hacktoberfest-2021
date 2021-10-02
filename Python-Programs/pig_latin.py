def startsWithVowel(word: str) -> bool:
    return word[0].lower() in "aeiou"


def translateWord(word: str) -> str:
    if startsWithVowel(word):
        return word + "yay"

    vowel_index = 0

    for index, letter in enumerate(word):
        if startsWithVowel(letter):
            vowel_index = index
            break

    return word[vowel_index:] + word[:vowel_index] + "ay"


def translateList(word_list: list[str]) -> list[str]:
    return [translateWord(word) for word in word_list]


if __name__ == "__main__":
    print(startsWithVowel("apple"))
    print(startsWithVowel("ball"))
    print(translateWord("hockey"))
    print(translateList(["hello", "I", "am", "very", "exited", "to", "see", "you"]))
