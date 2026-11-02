- Artificial Intelligence: Human intelligence exhibited by machines
- Machine learning: AI systems that learn from historical data
- Deep Learning: Machine learning models that mimic human brain functions 
- Generative AI: Deep learning models (foundation models) that create original content

# Machine Learning
A computer program is said to learn from experience $E$ with respect of tasks $T$ and performance measure $P$, if its performance at tasks $T$, as measured by $P$, improves with experience $E$.

The process of using machine learning algorithms to build models from data is called **learnnig** or **training**. The data used in the training phase is called training data, in which each sample is a training example, and the set of all training examples is called a training set. 
>The objective of machine learning is to find a hypothesis able to match or approximate ground-truth on unseen data 

## Tasks
Tasks can be: 
- Predictive: 
	- Classification -> binary or multiclass
	- Regression
	- ...
- Descriptive:
	- Clustering
	- Association rules 
	- ...
Supervised Learning: the label is provided by the user, e.g., classification, regression
Unsupervised learning: the label is not provided,e.g, clustering, dimensionality reduction
Predictive tasks: are usually supervised, while descriptive tasks are usually unsupervised 


In most cases data is assumed to be **i.i.d**: **independent** and **idetically distributed** 
- Independence: $P((x_{i},y_{i})| (x_{1},y_{1},\dots,(x_{i-1},y_{i-1}))= P((x_{i},y_{y}))$ for all $i$
- Identical Distribution: All instances are drawn from the same underlying distribution. This also means that the training data and the test data should come from the same distribution.



# Comparing the Activations
| Activation | Negative Inputs       | Main Benefit                          | Main trade-off                                                            |
| ---------- | --------------------- | ------------------------------------- | ------------------------------------------------------------------------- |
| ReLU       | Set to zero           | Cheap; exact sparsity                 | Units can die                                                             |
| Leaky ReLU | Linear slope $\alpha$ | Reduces dead units                    | Less sparse; choose $\alpha$                                              |
| GELU       | Smoothly attenuated   | Smooth self-gating via a gaussian CDF | More computatiion and no exact sparsity; gains are architecture dependent |
| SiLU       | Smoothly attenuated   | Smooth self-gating via a sigmoid      | More computation and no exact sparsity; gains are architecture-dependent  |
