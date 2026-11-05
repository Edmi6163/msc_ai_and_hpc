Most of supercomputer are today GPU based. New vendors in gpu is ARM (othern than nvidia,amd,intel).

HPC4AI: A small but complex and heterogeneous system with (~100 Kw): 
- a Cloud infrastructure with virtual machines gpu powered based on OpenStack
- an HPC workload manager with gpu nodes (bare-metal) managed by [[#SLURM]]
All servers and storages are interconnected by many network types and speed (from 1GBps to 400GBps) and topologies.

## How to access an HPC systems 
Usually, it uses the Secure Shell (SSH) protocal. 
```bash
ssh [options] username@host
```
examples: 
```bash
# HPC4AI example
ssh username@mercurio.hpc4ai.unito.it
# LabInfo
ssh stXXXX/spXXXX@slurm.labinfo.educ.di.unito.it
```
There are many ways to log into server, but the simpler is to use SSH keys, is it possible to create the first private/pub keys with `ssh-keygen -t ed25519`

The private key should stay secure in your account/notebook, the public key associated to the private one, should be enlisted in server's `~/.ssh/authorized_keys`

## Why Resource Management System 
Managing the resources of a supercomputer is NOT trivial. Resource (or Workload) management systems are required
Workload managers are used to manage the Cluster computing resources shared between users.
They mainly perform 3 functions: 
- Resource Allocation
- Manage the schedule (the beginning and end of program execution)
- Distribute the total workload and monitoring

Thre are many Workload managers: 
- SLURM (actually the most wide deployed solutions)
- PBS (tipically used in private companies environmnet)
- HITCONDOR (tipically used in physics environment)
The nodes of a cluster are divided into login nodes (entry, to use only for login and commands for the workload manager) and computational nodes
To use the compute nodes, you should know which Workload Manager/Job Scheduler is installed and use their specific commands

# SLURM
Simple Linux Utility for Resource Management. 
Computational nodes are subdivided into partitions. Partitions can be configured in different ways: limiting the number of hours (time limited partition), 

## SLURM Architecture
SLURM consists of a few components
- Client: interacts with the controller 

## SLURM Policy
SLURM assigns the available nodes of a partition until they are exhausted to the submissions with the highest priority
Two policies: 
- backfill algorithm
- priority queue alogrithm

- **Backfill algorithm**: The default algorithm attempts to schedule low-priority jobs if they do not prevent higher-priority jobs from starting at the scheduled time
	- Main disadvantage: depends a lot on the time parameter set by the user
- **Priority queue algorithm**: It uses a global queue, ordered according to a certain priority.
	- Main disadvantage: 

Proof of concept of a "slurm on your hands solution": Gitlab Repo: https://gitlab.di.unito.it/slurm/slurm_compose
NOTE: it works, but there is space for enhancing, so fork it and suggest pull-request

Big hpc systems: Linux MODULES
Linux modules in HPC environmnents allow users to dynamically manage software, multiple versions, and dependencies on a shared cluster without permanently altering shell configuration files or causing conflicts between packages
Tipical usage when you need to run your code on different facilities and for reproducibility the same library version are needed

### Labinfo Slurm cluster 
Host: slurm.educ.di.unito.it standard if calling from the internet
Host: slurm.labinfo.educ.unito.it from the labs itself
logging to with your username and password/ssh keys 
Local scratch area is available under `/tmp`

### Slurm commands
sinfo: view information about Slurm nodes and partition
sbatch: syntax `sbatch [options] [scripts]`
- submits a batch script to SLURM
- used to execute a job file
salloc: syntax `salloc [options] [command] [arguments]`
- allocate a set of nodes
- used to compile code (NOTE that code must be compiled on the computer node to get the compiler optimization hardware specific)
scancel: syntax `scancel job-id`
scontrol: provides information on the system
- scontrol show nodes: provides information on nodes
- scontrol show jobs: provides information on jobs


# Working with MPI/SLURM
Suggestions: Use always the OpenMPI configured and available in your system (our you can get in trouble)
To see configuration informatino exec the command: `ompi_info`
To tell slurm that should use MPI: 
- #todo 
- #todo 


