import pylab

pylab.rc('text', usetex=True)
pylab.rc('font', **{'family': 'serif', 'serif': ['Computer Modern']})

th1, th2, p1, p2 = pylab.loadtxt("lorentz.dat", unpack=True)
pylab.hist(th1, bins=50, normed=True)
pylab.xlabel(r"$\tan(\theta)$")
pylab.ylabel(r"$\pi(\tan(\theta))$")
pylab.title(r"Distribuzione angolare nel lab con $E_K=100\ \mathrm{GeV}$")
pylab.savefig("theta_lab.pdf")
pylab.clf()
pylab.hist(p1, bins=50, normed=True)
pylab.xlabel(r"$p_{z,\pi}\ \mathrm{[GeV]}$")
pylab.ylabel(r"$\pi(p_{z,\pi})$")
pylab.title(r"Distribuzione degli impulsi nel lab con $E_K=100\ \mathrm{GeV}$")
pylab.savefig("p_lab.pdf")

