import random
import subprocess
import sys
import itertools

EXE = r"f:\GitHubpr\MyCSES\.builds\Tasks_and_Deadlines.exe"

def brute(tasks):
    best = None
    for perm in itertools.permutations(tasks):
        t = 0
        score = 0
        for a,d in perm:
            t += a
            score += d - t
        if best is None or score > best:
            best = score
    return best


def run_prog(tasks):
    inp = str(len(tasks)) + "\n"
    for a,d in tasks:
        inp += f"{a} {d}\n"
    proc = subprocess.run([EXE], input=inp.encode(), stdout=subprocess.PIPE)
    out = proc.stdout.decode().strip()
    try:
        return int(out)
    except:
        print('Program output not integer:', out)
        sys.exit(2)


def random_test(iterations=200):
    for it in range(iterations):
        n = random.randint(1,7)
        tasks = [(random.randint(1,10), random.randint(1,10)) for _ in range(n)]
        expected = brute(tasks)
        got = run_prog(tasks)
        if expected != got:
            print('Mismatch on test:', tasks)
            print('Expected:', expected)
            print('Got:', got)
            return 1
    print('All', iterations, 'random tests passed')
    return 0

if __name__ == '__main__':
    random.seed(1)
    exit(random_test(500))
