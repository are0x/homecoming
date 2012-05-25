# coding: utf-8

import sys
import re

if __name__ == '__main__':

    def make_function_hiragana():
        re_katakana = re.compile(u'[ァ-ヴ]')
        def hiragana(text):
            """ひらがな変換"""
            return re_katakana.sub(lambda x: unichr(ord(x.group(0)) - 0x60), text)
        return hiragana
    hiragana = make_function_hiragana()

    if 'firstname' in sys.argv[1]:
        # firstname
        with open(sys.argv[1]) as infile:
            for row in infile:
                pron = row.split()[0]
                for name in row.split()[3:]:
                    print name, hiragana(pron)
    elif 'lastname' in sys.argv[1]:
        # lastname
        with open(sys.argv[1]) as infile:
            for row in infile:
                name, pron = row.split()[1:3]
                if '■' in name: continue
                print name, hiragana(pron)

