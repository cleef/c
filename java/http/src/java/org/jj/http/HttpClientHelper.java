

/*
 *  * To change this template, choose Tools | Templates
 *   * and open the template in the editor.
 *    */
package com.plato.service.common.api.client;

import com.plato.service.common.api.XmlHelper;
import com.plato.service.searchengine.SearchRequest;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.String;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.conn.ClientConnectionManager;
import org.apache.http.conn.scheme.PlainSocketFactory;
import org.apache.http.conn.scheme.Scheme;
import org.apache.http.conn.scheme.SchemeRegistry;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.impl.conn.tsccm.ThreadSafeClientConnManager;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpParams;
import org.apache.http.protocol.HTTP;

/**
 *  *
 *   * @author lee
 *    */
public class HttpClientHelper {

	    static HttpClient client = getClient();

	        static HttpClient getClient() {
			        HttpParams params = new BasicHttpParams();
				        SchemeRegistry registry = new SchemeRegistry();
					        registry.register(new Scheme("http", PlainSocketFactory.getSocketFactory(), 80));
						        ClientConnectionManager cm = new ThreadSafeClientConnManager(params, registry);
							        HttpClient client = new DefaultHttpClient(cm, params);

								        return client;
									    }

		    public static String post(String url, String content) throws IOException {
			            HttpPost post = new HttpPost(url);

				            try {
						                StringEntity se = new StringEntity(content, HTTP.UTF_8);
								            se.setContentType("text/xml");
									                post.setHeader("Content-Type", "application/soap+xml;charset=UTF-8");
											            post.setEntity(se);

												                HttpResponse response = client.execute(post);
														            InputStream input = response.getEntity().getContent();

															                String ret = read(input);
																	            response.getEntity().consumeContent();

																		                return ret;
																				        } catch (IOException e) {
																						            post.abort();
																							                throw e;
																									        }
					        }

		        public static String get(String url) throws IOException {
				        HttpGet get = new HttpGet(url);

					        try {
							            HttpResponse response = client.execute(get);
								                InputStream input = response.getEntity().getContent();

										            String ret = read(input);
											                response.getEntity().consumeContent();

													            return ret;
														            } catch (IOException e) {
																                get.abort();
																		            throw e;
																			            }

						    }

			    public static String read(InputStream input) throws IOException {
				            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
					            byte[] byteArray = new byte[1024];
						            int count = 0;
							            while ((count = input.read(byteArray, 0, byteArray.length)) > 0) {
									                outputStream.write(byteArray, 0, count);
											        }

								            return new String(outputStream.toByteArray(), "UTF-8");
									        }

			        public static void testGet() throws IOException {
					        String url = "http://localhost:11100/search/%E4%B8%8A%E6%B5%B7/groupby/food/p1/discount";
						        String output = get(url);
							        System.out.println(output);
								    }

				    public static void testPost() throws IOException {
					            String url = "http://localhost:11100/search/";

						            SearchRequest request = new SearchRequest();
							            request.setCity("上海");
								            request.setCategroy("food");
									            request.setSortType(SearchRequest.SORT_BY_RANK);

										            String content = XmlHelper.toXml(request);
											            String output = post(url, content);
												            System.out.println(output);
													        }

				        public static void main(String[] args) throws IOException {
						        testGet();
							        testPost();
								    }
}

