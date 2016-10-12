/*******************************************************************************
 * basic1.c 
 * This describes the basic outline of a machine learning alogrithm
 *
 * @author: AdityaAtulTewari
 ******************************************************************************/

data = load_data(data_early.csv);
model = (build_model(data, target = "100 Free"));
new_data = load_data(data_late.csv);
predictions = model.predict(new_data);

