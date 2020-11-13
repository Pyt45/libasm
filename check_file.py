from os import path

def check_file(filename):
    if path.exists(str(filename)):
        return True
    return False

def check_exists(filename):
    try:
        f = open(str(filename))
        f.close()
        return True
    except FileNotFoundError:
        return False
    # try:
    #     with open(str(filename)) as f:
    #         f.read()
    # except IOError:
    #     print("\n file does not exist " + str(filename))
    # finally:
    #     f.close()