#ifndef deep_belief_network_H 
#define deep_belief_network_H
#include "rbm.h"

typedef struct {
  int n_layers;      // Number of layers in the data ...
  int *layer_sizes;  // Number of nodes in the upper 'output' layer.

  int n_rbms;        // For convenience ... it's ALWAYS= n_layers-1 ... or it's wrong.
  rbm_t *rbms;       // Pointer to a layer of restricted boltzman machines.
  
  // Learning functions ... for use with refining network weights by backpropagation.
  double learning_rate;
  int batch_size;         // Specifies the batch size for training during backprop.
  
  // Should I implement using momentum method here too?! 
} dbn_t;

SEXP train_dbn_R(SEXP dbn_r, SEXP training_data_r, SEXP n_epocs_r, SEXP n_threads_r);
SEXP backpropagation_dbn_R(SEXP dbn_r, SEXP training_data_r, SEXP training_labels_r, SEXP n_epocs_r, SEXP n_threads_r);
SEXP predict_dbn_R(SEXP dbn_r, SEXP input_r, SEXP n_threads_r);

double *get_layer_outputs(dbn_t *dbn, int layer, double *input, int n_inputs);
delta_w_t *alloc_dwt_from_dbn(dbn_t *dbn);
dbn_t *dbn_r_to_c(SEXP dbn_r);

#endif

