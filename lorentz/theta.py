import pylab

pylab.rc('text', usetex=True)
pylab.rc('font', **{'family': 'serif', 'serif': ['Computer Modern']})

theta = pylab.loadtxt('theta.dat', unpack=True)
pylab.hist(theta, bins=30, normed=True, label=r"funzione $\theta()$")
x = pylab.linspace(0,pylab.pi,500)
pylab.plot(x,pylab.sin(x)/2., label=r"$\frac{1}{2}\sin(\theta)$")
pylab.legend()
pylab.ylabel(r"$\pi(\theta)$")
pylab.xlabel(r"$\theta$")
pylab.title(r"Distribuzione dell'output della funzione $\theta()$, ovvero la $\theta^{cm}$")
pylab.savefig("theta.pdf")